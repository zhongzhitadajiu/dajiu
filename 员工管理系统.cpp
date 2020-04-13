#include"stdio.h"
#include"stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2



typedef struct LNode
{
    char num[10];
    char name[20];
    char sex[10];
    char birth[10];
    char edu[10];
    char post[20];
    char tel[20];
    char address[30];
    struct LNode *next;
}LNode,*Linklist;//����ڵ�����



int Initlist(Linklist &L)
{
    L=(Linklist)malloc(sizeof(LNode));
    if(!L)
        return (0);
    L->next=NULL;
        return OK;
}//��ʼ��������



int CreatList(Linklist &L)
{
    Linklist p;
    p=(Linklist)malloc(sizeof(LNode));
    if(!p)
        {
            return (0);
        }
        else
            {
                printf("������Ա����ţ�\n");
                scanf("%s",p->num);
                printf("������Ա��������\n");
                scanf("%s",p->name);
                printf("������Ա���Ա�\n");
                scanf("%s",p->sex);
                printf("������Ա���������£�\n");
                scanf("%s",p->birth);
                printf("������Ա��ѧ����\n");
                scanf("%s",p->edu);
                printf("������Ա��ְ��\n");
                scanf("%s",p->post);
                printf("������Ա���绰��\n");
                scanf("%s",p->tel);
                printf("������Ա��סַ��\n");
                scanf("%s",p->address);
            }
    p->next=L->next;
    L->next=p;
}//ͷ�巨���ɵ�����



void Display(Linklist &L)
{
    Linklist p;
    for(p=L->next;p;p=p->next)
        {
            printf("��    �� ��  %s\n",p->num);
            printf("��    �� ��  %s\n",p->name);
            printf("��    �� ��  %s\n",p->sex);
            printf("�������� ��  %s\n",p->birth);
            printf("ѧ    �� ��  %s\n",p->edu);
            printf("ְ    �� ��  %s\n",p->post);
            printf("��    �� ��  %s\n",p->tel);
            printf("ס    ַ ��  %s\n",p->address);
            printf("-----------------------------------------\n");
        }
}//��ʾ����Ա����Ϣ



int SearchNum(Linklist &L,char num[10])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->num,num)==0)
            {
                printf("��    �� ��  %s\n",p->num);
                printf("��    �� ��  %s\n",p->name);
                printf("��    �� ��  %s\n",p->sex);
                printf("�������� ��  %s\n",p->birth);
                printf("ѧ    �� ��  %s\n",p->edu);
                printf("ְ    �� ��  %s\n",p->post);
                printf("��    �� ��  %s\n",p->tel);
                printf("ס    ַ ��  %s\n",p->address);
                printf("-----------------------------------------\n");
            }
            p=p->next;
        }
        return OK;
}//��Ų�ѯ



int SearchName(Linklist &L,char name[20])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->name,name)==0)
            {
                printf("��    �� ��  %s\n",p->num);
                printf("��    �� ��  %s\n",p->name);
                printf("��    �� ��  %s\n",p->sex);
                printf("�������� ��  %s\n",p->birth);
                printf("ѧ    �� ��  %s\n",p->edu);
                printf("ְ    �� ��  %s\n",p->post);
                printf("��    �� ��  %s\n",p->tel);
                printf("ס    ַ ��  %s\n",p->address);
                printf("-----------------------------------------\n");
            }
            p=p->next;
        }
        return OK;
}//������ѯ



int SearchSurname(Linklist &L,char surname[20])
{
    LNode *p;
    int i=0,n,k=0;
    n=strlen(surname);
    p=L;
    while(p)
    {
        k=0;
        for(i=0;i<n;i++)
            {
                if(surname[i]==p->name[i])
                    k++;
            }
        if(k==n)
        {
            printf("��    �� ��  %s\n",p->num);
            printf("��    �� ��  %s\n",p->name);
            printf("��    �� ��  %s\n",p->sex);
            printf("�������� ��  %s\n",p->birth);
            printf("ѧ    �� ��  %s\n",p->edu);
            printf("ְ    �� ��  %s\n",p->post);
            printf("��    �� ��  %s\n",p->tel);
            printf("ס    ַ ��  %s\n",p->address);
            printf("-----------------------------------------\n");
        }
        p=p->next;
    }
    return OK;
}//���ϲ�ѯ



void SortNum(Linklist &L ,char num[10])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->num,q->num ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//�������



void SortName(Linklist &L ,char name[20])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
            {
                if((strcmp( p->next->name,q->name ))>0 )
                {
                    m=p;
                    q=p->next  ;
                }
            }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//��������



void SortSex(Linklist &L ,char sex[10])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->sex,q->sex))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//�Ա�����



void SortBirth(Linklist &L ,char birth[10])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->birth,q->birth ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//������������



void SortEdu(Linklist &L ,char edu[20])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->edu,q->edu ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q;
        }
    L=Largest;
    Display(L);
}//ѧ������



void SortPost(Linklist &L ,char post[20])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->post,q->post ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//ְ������



void SortTel(Linklist &L ,char tel[20])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->tel,q->tel ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q;
        }
    L=Largest;
    Display(L);
}//�绰����



void SortAddress(Linklist &L ,char address[30])
{
    Linklist Largest;
    Linklist p,q,m;
    Largest=(Linklist)malloc(sizeof(LNode));
    Largest->next =NULL;
    while(L->next)
        {
            for(q=L->next ,p=L->next  ;p->next ;p=p->next )
                {
                    if((strcmp( p->next->address,q->address ))>0 )
                    {
                        m=p;
                        q=p->next  ;
                    }
                }
            if(q==L->next)
                {
                    L->next =L->next->next ;
                }
            else
                {
                    m->next =q->next ;
                }
            q->next =Largest->next ;
            Largest->next =q ;
        }
    L=Largest;
    Display(L);
}//סַ����



int Alter(Linklist &L,char num[10])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->num,num)==0)
                {
                    printf("��������Ա����ţ�\n");
                    scanf("%s",p->num);
                    printf("��������Ա��������\n");
                    scanf("%s",p->name);
                    printf("��������Ա���Ա�\n");
                    scanf("%s",p->sex);
                    printf("��������Ա���������£�\n");
                    scanf("%s",p->birth);
                    printf("��������Ա��ѧ����\n");
                    scanf("%s",p->edu);
                    printf("��������Ա��ְ��\n");
                    scanf("%s",p->post);
                    printf("��������Ա���绰��\n");
                    scanf("%s",p->tel);
                    printf("��������Ա��סַ��\n");
                    scanf("%s",p->address);
                    printf("���³ɹ���\n");
                }
            p=p->next;
        }
        return OK;
}//����



int Delete(Linklist &L,char num[10])
{
    LNode *p;
    LNode *r;
    p=L->next;
    r=L;
    while(!(strcmp(p->num,num)==0)&&p)
        {
            r=p;
            p=p->next;
        }
    if(!p)
        printf("\nɾ��λ�ò�����\n");
    else
        {
            r->next=p->next;
            free(p);
            printf("ɾ���ɹ���\n");
        }
        return OK;
}//�����ɾ��



//������
int main()
{
    Linklist L;
    int a;
    char m;
    char num[10];
    char name[20];
    char surname[20];
    char sex[10];
    char birth[10];
    char edu[20];
    char post[20];
    char tel[20];
    char address[30];
    Initlist(L);
    int y;
    int x=1;
    while(x)
        {
            printf("-----------------------------------------\n");
            printf("��ӭ����Ա������ϵͳ��\n");
            printf("-----------------------------------------\n");
            printf("1-���Ա����Ϣ\n");
            printf("2-��ѯԱ����Ϣ\n");
            printf("3-����Ա����Ϣ\n");
            printf("4-����Ա����Ϣ\n");
            printf("5-ɾ��Ա����Ϣ\n");
            printf("6-�˳�\n");
            printf("��ѡ���������Իس�����:\n");
            scanf("%d",&y);
            switch(y)
            {
                case 1: CreatList(L);
                do
                    {
                        printf("-----------------------------------------\n");
                        printf("�������?(Y/N)\n");
                        getchar();
                        scanf("%c",&m);
                        if(m=='Y')
                            {
                                CreatList(L);
                            }
                    }
                while(m!='N');
                    break;

                case 2: printf("�������ѯ��ʽ(����Ų�ѯ�밴1,��������ѯ�밴2,�����ϲ�ѯ�밴3)\n");
                scanf("%d",&a);
                if(a==1)
                    {
                        printf("����������ѯԱ�����\n");
                        scanf("%s",&num);
                        printf("-----------------------------------------\n");
                        SearchNum(L,num);
                    }
                if(a==2)
                    {
                        printf("����������ѯԱ������\n");
                        scanf("%s",&name);
                        printf("-----------------------------------------\n");
                        SearchName(L,name);
                    }
                if(a==3)
                    {
                        printf("����������ѯԱ������\n");
                        scanf("%s",&surname);
                        printf("-----------------------------------------\n");
                        SearchSurname(L,surname);
                    }
                    break;

                case 3: printf("��ѡ����������:1.���2.����3.�Ա�4.��������5.ѧ��6.ְ��7.�绰8.��ַ0.�˳�\n");
                scanf("%d",&a);
                if(a==1)
                    {
                        printf("���������:\n");
                        printf("-----------------------------------------\n");
                        SortNum(L,num);
                    }
                if(a==2)
                    {
                        printf("����������:\n");
                        printf("-----------------------------------------\n");
                        SortName(L,name);
                    }
                if(a==3)
                    {
                        printf("���Ա�����:\n");
                        printf("-----------------------------------------\n");
                        SortSex(L,sex);
                    }
                if(a==4)
                    {
                        printf("��������������:\n");
                        printf("-----------------------------------------\n");
                        SortBirth(L,birth);
                    }
                if(a==5)
                    {
                        printf("��ѧ������:\n");
                        printf("-----------------------------------------\n");
                        SortEdu(L,edu);
                    }
                if(a==6)
                    {
                        printf("��ְ������:\n");
                        printf("-----------------------------------------\n");
                        SortPost(L,post);
                    }
                if(a==7)
                    {
                        printf("���绰����:\n");
                        printf("-----------------------------------------\n");
                        SortTel(L,tel);
                    }
                if(a==8)
                    {
                        printf("��סַ����:\n");
                        printf("-----------------------------------------\n");
                        SortAddress(L,address);
                    }
                    break;

                case 4: printf("������������Ա�����:\n");
                getchar();
                scanf("%s",&num);
                Alter(L,num);
                break;

                case 5: printf("��������ɾ��Ա�����:\n");
                getchar();
                scanf("%s",&num);
                Delete(L,num);
                break;

                case 6: x=0;
                break;

                default:
                    printf("�밴����ʾ������ȷ��ţ�����\n");
                    break;
            }

        }

}
