#include <iostream>
using namespace std;
struct node
{
    int info;
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
NODE *getNODE(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->info = x;
    p->pnext = NULL;
}
void addhead(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    p->pnext = l.phead;
    p = l.phead;
}
void addtail(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    l.ptail->pnext = p;
    p = l.ptail;
}
int dem(LIST &l)
{
    int a(0);
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        a++;
    }
    return a;
}
NODE *find_DL(LIST l, NODE *k)
{
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info == k->info)
            return p;
        break;
    }
}
NODE *tach_HEAD(LIST &l)
{
    if (l.phead == NULL)
    {
        return NULL;
    }
    if (l.phead = l.ptail)
    {
        NODE *p = l.phead;
        l.phead = l.ptail = NULL;
        return p;
    }
    NODE *p = l.phead;
    l.phead = l.phead->pnext;
    p->pnext = NULL;
    return p;
}
int sum_chan(LIST l)
{
    int sum(0);
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info % 2 == 0)
            sum++;
    }
    return sum;
}
int MAXX(LIST &l)
{
    int a = l.phead->info;
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        a = max(a, p->info);
    }
    return a;
}
NODE *tim_kecuoi(LIST &l)
{
    if (l.phead == NULL)
    {
    }
    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->pnext == l.ptail)
            return p;
    }
}
NODE *tach_node(LIST &l)
{
}
int main()
{
    LIST l;
    Init(l);
    int n;
    cout << "nhap so luong danh sach : ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cout << "\nnhap gia tri : ";
        cin >> x;
        NODE *p = new NODE;
        p = getNODE(x);
        addhead(l, p);
    }
}