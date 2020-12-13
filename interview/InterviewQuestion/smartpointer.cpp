//https://www.cnblogs.com/wuyepeng/p/9741241.html
//本文介绍c++里面的四个智能指针: auto_ptr, shared_ptr, weak_ptr, unique_ptr 其中后三个是c++11支持，并且第一个已经被c++11弃用。
//为什么要使用智能指针：我们知道c++的内存管理是让很多人头疼的事，当我们写一个new语句时，一般就会立即把delete语句直接也写了，但是我们不能避免程序还未执行到delete时就跳转了或者在函数中没有执行到最后的delete语句就返回了，如果我们不在每一个可能跳转或者返回的语句前释放资源，就会造成内存泄露。使用智能指针可以很大程度上的避免这个问题，因为智能指针就是一个类，当超出了类的作用域是，类会自动调用析构函数，析构函数会自动释放资源。下面我们逐个介绍。

#include <iostream>
#include <memory> //智能指针引用的头文件。
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::auto_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

class Smart
{
public:
    Smart(string str)
    {
        m_str = str;
        cout << "Smart Constructor======m_str===" << m_str << endl;
    }

    ~Smart()
    {
        cout << "Smart Destructor======m_str===" << m_str << endl;
    }

    string& getStr()
    {
        return m_str;
    }

    void setStr(string s)
    {
        m_str = s;
    }

    void print()
    {
        cout << "print======m_str===" << m_str << endl;
    }

private:
    string m_str;
};

unique_ptr<Smart> fun()
{
    return unique_ptr<Smart>(new Smart("fun函数"));
}

//智能指针可以像类的原始指针一样访问类的public成员，成员函数get()返回一个原始的指针，成员函数reset()重新绑定指向的对象，而原来的对象则会被释放。
//注意我们访问auto_ptr的成员函数时用的是“.”，如：get(), reset()，访问指向对象的成员时用的是“->”
//我们也可以声明一个空智能指针auto_ptr<Smart> pSmart();

/*
int main()
{
    std::auto_ptr<Smart> pSmart(new Smart("this is Smart pointer"));//调用构造函数
    pSmart->setStr("hello ");//修改成员变量的值。
    pSmart->print();//输出hello
    pSmart.get()->print();//输出hello,注意访问的方式是“.”
    pSmart->getStr() += "world!";
    (*pSmart).print(); //输出hello world!
    //成员函数reset()重新绑定指向的对象，而原来的对象则会被释放，所以这里会调用一次构造函数，
    //还有调用一次析构函数释放掉之前的对象。
    cout << endl;
    pSmart.reset(new Smart("this is Smart pointer2"));
    pSmart->print();//输出这this is Smart pointer2
    cout << endl;
    //当我们对智能指针进行赋值时，如pSmart = pSmart2, pSmart会接管pSmart2原来的内存管理权，pSmart2会变为空指针，如果pSmart原来不为空，则它会释放原来的资源来管理pSmart2的资源，基于这个原因，应该避免把auto_ptr放到容器中，因为算法对容器操作时，很难避免STL内部对容器现了赋值传递操作，这样会使用容器中很多元素被置为NULL，
    auto_ptr<Smart> pSmart2(new Smart("A2"));
    pSmart = pSmart2;
    //判断一个智能指针是否为空不能使用if(pSmart2 == nullptr),应该调用get()函数，如下：
    if(pSmart2.get() == nullptr)
        cout << "pSmart2 is NULL============" << endl;

    auto_ptr<Smart> pSmart3(new Smart("A3"));
    //release函数值得注意，这个函数只是把智能指针赋值为空，但是它原来指向的内存并没有被释放，相当于它只是释放了对资源的所有权，下载代码的执行结果看，A3的析构函数没有被调用。
    pSmart3.release();

    return 0;//此时还剩下一个对象，调用一次析构函数释放该对象。
}
*/


//===============================================================
//unique_ptr是一个独享所有权的智能指针，它提供了严格意义上的所有权，包括：
//1、拥有它指向的对象。
//2、无法进行复制构造，无法进行复制赋值操作。即无法使用两个unique_ptr指向同一个对象。但是可以进行移动构造和移动赋值操作。
//3、保存指向某个对象的指针，当它本笛被删除释放的时候，会使用给定的删除器释放它指向的对象。
//union_ptr可以实现如下功能：
//1、为动态申请的内存提供异常安全
//2、将动态申请的内存所有权传递给某函数
//3、从某个函数返回动态申请内存的所有权
//4、在容器中保存指针
//5、auto_ptr应该具有的功能。

/*
int main()
{
    unique_ptr<Smart> pSmart(new Smart("hello "));//调用构造函数
    unique_ptr<Smart> pSmart2(new Smart("world!"));//调用构造函数
    pSmart->print();//输出hello
    cout << endl;
    //不能直接pSmart2 = pSmart;调用了move后pSmart2原本的对象会被释放，pSmart2对象指向原本pSmart对象的内存，
    pSmart2 = std::move(pSmart);
    //pSmart = std::move(pSmart2);//对比测试，pSmart的内存被释放，输出hello
    if(nullptr == pSmart)//因为两个unique_ptr不能指向同一内存地址,经过move后，pSmart赋为NULL
    {
        cout << "pSmart===========nullptr" << endl;
    }
    cout << endl;
    Smart *pA = pSmart2.release();//release成员函数把pSmart2指针赋为空，但并没有释放指向的内存，所以此时pA指针指向原本pSmart2指向的内存
    pA->print();//输出hello   pA没有被释放
    //delete pA;

    pSmart.reset(pA);//重新绑定对象，原来的pSmart对象会被释放掉，但是pSmart对象本来就释放过了，所以这里不会再调用析构函数了。
    pSmart->print();//输出hello
    cout << endl;
    pSmart2 = fun();//这里可以用=，因为使用了移动构造函数，函数返回一个unique_ptr会自动调用移动构造函数
    pSmart2->print(); //输出fun函数

    return 0;//此时程序中还有两个对象，调用两次析构函数释放对象
}
*/
//=========================================================
//share_ptr:从名字share就可以看出了资源可以被多个指针共享，它使用计数机制来表明资源被几个指针共享，
//可以通过成员函数use_count()来查看资源的所有者个数。除了可以通过new来构造，还可以通过传入auto_ptr
//unique_ptr,weak_ptr来构造。当我们调用release时，当前指针会释放资源所有权，计数减一，
//当计数等0时，资源会被释放，


/*
int main()
{
    shared_ptr<Smart> pSmart(new Smart("hello "));//调用构造函数
    shared_ptr<Smart> pSmart2(new Smart("world!"));//调用构造函数
    cout << pSmart2->getStr() << endl;//输出world!
    cout << pSmart2.use_count() << endl;//显示此时资源被几个指针共享，输出1
    pSmart = pSmart2;// "world!"的引用次数加1，“hello”销毁，
    pSmart->print();//输出world!
    cout << pSmart2.use_count() << endl;//该指针指向的资源被几个指针共享，输出2
    cout << pSmart.use_count() << endl;//指向过两个资源 2
    cout << endl;
    pSmart.reset();//重新绑定对象，绑定一个空对象，当此时指针指向的对象还有其他指针能指向就不会释放该对象的内存空间。
    cout << "pSmart.reset=============" << endl;
    cout << endl;
    pSmart2.reset();//此时“world”销毁，指针指向的内存空间上的指针为0，就释放了该内存，
    cout << "done!" << endl;
    return 0;
}
*/


//==================================================================================
//weak_ptr是用来解决shared_ptr相互引用时的列锁问题，如果说两个shared_ptr相互引用，那么这两个指针的引用计数永远不可能下降为0，资源永远不会释放。它是对对象的一种弱引用，不会增加对象的引用计数，和shared_ptr之间可以相互转化，shared_ptr可以直接赋值给它，它可以通过调用lock函数来获取shared_ptr.

class SmartB;

class SmartA
{
public:
    //shared_ptr<SmartB> pSB;
    weak_ptr<SmartB> pSB;
    SmartA(string str)
    {
        m_str = str;
        cout << "SmartA Constructor======m_str===" << m_str << endl;
    }

    ~SmartA()
    {
        cout << "SmartA Destructor======m_str===" << m_str << endl;
    }

    string& getStr()
    {
        return m_str;
    }

    void setStr(string s)
    {
        m_str = s;
    }

    void print()
    {
        cout << "print======m_str===" << m_str << endl;
    }

private:
    string m_str;
};

class SmartB
{
public:
    shared_ptr<SmartA> pSA;
    SmartB(string str)
    {
        m_str = str;
        cout << "SmartB Constructor======m_str===" << m_str << endl;
    }
    ~SmartB()
    {
        cout << "SmartB Destructor======="<< endl;
    }
    string& getStr()
    {
        return m_str;
    }

    void setStr(string s)
    {
        m_str = s;
    }

    void print()
    {
        cout << "print======m_str===" << m_str << endl;
    }

private:
    string m_str;
};

void funAB()
{
    shared_ptr<SmartB> pb(new SmartB("hello "));
    shared_ptr<SmartA> pa(new SmartA("world!"));
    pb->pSA = pa;
    pa->pSB = pb;
    cout << endl;
    //不能用pa->pSB访问print函数，因为他是weak_ptr，需要转化为shared_ptr
    shared_ptr<SmartB> p = pa->pSB.lock();
    p->print();
    cout << "pb.use_count()======" << pb.use_count() << endl;
    cout << "pa.use_count()======" << pa.use_count() << endl;
}


/*
int main()
{
    funAB();
    //可以看到funAB函娄中的pa,pb之间相互引用，两个资源的引用计数为2，当要跳出函数时，智能指针pa，pb析构时两个资源引用计数会减一，但是两者引用计数还是为1，导致跳出函数时资源没有被释放（AB的析构函数没有被调用），如果把其中一个改为weak_ptr就可以了，我们把SmartA里的改为weak_ptr<SmartB> pSB;这样的话，资源SmartB的引用开始就只有1，当pb析构时，SmartB的计数变为0，SmartB得到释放，SmartB释放的同时也会使SmartA的计数减一，同时pa析构时使SmartA的计数减一，那么SmartA的计数为0，SmartA得到释放。
    return 0;
}

*/


