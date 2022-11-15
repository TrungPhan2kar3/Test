#include <iostream>
#include <string>
using namespace std;
struct shop
{
    string name;
    int so_mat_hang;
    int danh_gia;
    float khoang_cach;
};
struct node
{
    shop data;
    struct node *pnext;
};
typedef struct node NODE;
struct list
{
    NODE *phead;
    NODE *ptail;
};
typedef struct list LIST;
NODE khoitao(LIST &l)
{
    l.phead = NULL;
    l.ptail = NULL;
}
NODE *khoitaonode(shop x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "khong du bo nho de cap phat ! ";
        return NULL;
    }
    else
    {
        p->data = x;
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
void them_vao_dau(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        p->pnext = l.phead; // cho con trỏ của node cần thêm là code p liên kết đến node đầu phead
        l.phead = p;        // cập nhật lại phead chính là node p
    }
}
void nhap(LIST &l, int n)
{
    for (int i = 0; i < n; ++i)
    {
        shop x;
        cout << "\nnhap ten cua hang : ";
        cin.ignore();
        getline(cin, x.name);
        cout << "so mat hang cua cua hang : ";
        cin >> x.so_mat_hang;
        cout << "ty le danh gia : ";
        cin >> x.danh_gia;
        cout << "khoang cach den cua hang : ";
        cin >> x.khoang_cach;
        NODE *p = khoitaonode(x); // khởi tạo 1 cái node số nguyên
        them_vao_cuoi(l, p);      // them node p vao dau dslk don
    }
}
void nhapdau(LIST &l, int n)
{
    for (int i = 0; i < n; ++i)
    {
        shop x;
        cout << "\nnhap ten cua hang : ";
        cin.ignore();
        getline(cin, x.name);
        cout << "so mat hang cua cua hang : ";
        cin >> x.so_mat_hang;
        cout << "ty le danh gia : ";
        cin >> x.danh_gia;
        cout << "khoang cach den cua hang : ";
        cin >> x.khoang_cach;
        NODE *p = khoitaonode(x); // khởi tạo 1 cái node số nguyên
        them_vao_dau(l, p);       // them node p vao dau dslk don
    }
}
void xuat(LIST l)
{
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        cout << (k->data).name << "\t";
        cout << (k->data).so_mat_hang << "\t";
        cout << (k->data).danh_gia << "\t";
        cout << (k->data).khoang_cach << "\n\n";
    }
}
void tyledanhgia(LIST l)
{
    for (NODE *k = l.phead; k != NULL; k = k->pnext)
    {
        for (NODE *q = k->pnext; q != NULL; q = q->pnext)
        {
            if (k->data.danh_gia > q->data.danh_gia)
            {
                swap(k->data, q->data);
            }
        }
    }
}
int main()
{
    LIST l;
    khoitao(l);
    int n;
    cout << "nhap so luong n : ";
    cin >> n;
    nhap(l, n);
    tyledanhgia(l);
    xuat(l);
    return 0;
}