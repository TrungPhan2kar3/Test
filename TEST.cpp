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
void khoitao(LIST &l)
{
    l.phead = NULL;
    l.ptail = NULL;
}
NODE *khoitaonode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "khong du bo nho de cap phat ! ";
        return NULL;
    }
    else
    {
        p->info = x;
        p->pnext = NULL;
        return p;
    }
}
void them_vao_cuoi(LIST &l, NODE *p)
{
    // danh sách đang rỗng
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p; // node dau cung chinh la code cuoi va la p
    }
    else
    {
        l.ptail->pnext = p; // cho con tro ptail lien ket voi node p
        l.ptail = p;        // cap nhat lai p la node cuoi la node ptail
    }
}
void nhap(LIST &l, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cout << "\nNhap gia tri so nguyen : ";
        cin >> x;
        NODE *p = khoitaonode(x); // khởi tạo 1 cái node số nguyên
        them_vao_cuoi(l, p);      // them node p vao dau dslk don
    }
}
void xuat(LIST l)
{
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        cout << k->info << "\t";
    }
}
int dem_so_le(LIST l)
{
    int temp = 0;
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        if (k->info & 2 != 0)
            temp++;
    }
    return temp;
}
int tong(LIST l)
{
    int sum = 0;
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        sum += k->info;
    }
    return sum;
}
void sapxep(LIST l)
{
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        for (NODE *q = k->pnext; q != NULL; q = q->pnext)
        {
            if (k->info > q->info)
            {
                swap(k->info, q->info);
            }
        }
    }
}
int main()
{
    LIST l;
    khoitao(l);
    int n;
    cout << "nhap so luong : ";
    cin >> n;
    nhap(l, n);
    cout << "\n\n DANH SACH LIEN KET DON \n";
    sapxep(l);
    xuat(l);
}