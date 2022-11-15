#include <iostream>
using namespace std;
struct KS
{
    int soP;
    char loaiP;
    int tinhtrang;
};
struct node
{
    KS info;
    struct node *pnext;
};
typedef struct node NODE;
struct list
{
    NODE *phead;
    NODE *ptail;
};
typedef struct list LIST;
void Init(LIST &l)
{
    l.phead = NULL;
    l.ptail = NULL;
}
NODE *getNODE(KS x)
{
    NODE *k = new NODE;
    if (k == NULL)
        return NULL;
    else
    {
        k->info = x;
        k->pnext = NULL;
        return k;
    }
}
void Addtail(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    l.ptail->pnext = p;
    l.ptail = p;
}
void xuat(LIST l)
{
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        cout << "\nso phong : " << p->info.soP << "\t loai phong : " << p->info.loaiP << "\t ting trang : " << p->info.tinhtrang;
    }
}
void thong_ke(LIST &l)
{
    int a(0), b(0), c(0), d(0);
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info.loaiP == 'A')
            a++;
        else if (p->info.loaiP == 'B')
            b++;
    }
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info.tinhtrang == 1)
            c++;
        else
            d++;
    }
    cout << "so phong khach san loai phong don la : " << a << "\n";
    cout << "so phong khach san loai phong doi la : " << b << "\n";
    cout << "\n so phong khach san da co khach la : " << c << "\n";
    cout << "so phong khach san con trong la : " << d << "\n";
}
int doanhthu(LIST l)
{
    int sum(0);
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info.loaiP == 'A')
            sum += 200;
        else if (p->info.loaiP == 'B')
            sum += 350;
    }
    return sum;
}
void removePhong(LIST &l)
{
    int x;
    cout << "nhap so phong can xoa : ";
    cin >> x;
    NODE *p = l.phead;
    NODE *k = l.phead->pnext;
    if (l.phead->info.soP != x)
    {
        while (k != NULL)
        {
            if (k->info.soP == x)
            {
                p->pnext = k->pnext;
                k->pnext = NULL;
            }
            p = p->pnext;
            k = k->pnext;
        }
    }
    else
    {
        p = l.phead;
        if (l.phead->info.soP == x)
        {
            l.phead = l.phead->pnext;
            p = NULL;
        }
    }
}
int main()
{
    LIST l;
    Init(l);
    int n;
    cout << "nhap so luong phong : ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        KS x;
        cout << "\nnhap so phong : ";
        cin >> x.soP;
        cout << "nhap loai phong : ";
        cin >> x.loaiP;
        cout << "nhap tinh trang : ";
        cin >> x.tinhtrang;
        NODE *p = getNODE(x);
        Addtail(l, p);
    }
    xuat(l);
    cout << "\n----------------------\n";
    thong_ke(l);
    cout << "\n----------------------\n";
    cout << "\n\n doanh thu la : " << doanhthu(l);
    cout << "\n----------------------\n";
    removePhong(l);
    xuat(l);
}
