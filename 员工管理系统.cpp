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
}LNode,*Linklist;//定义节点类型



int Initlist(Linklist &L)
{
    L=(Linklist)malloc(sizeof(LNode));
    if(!L)
        return (0);
    L->next=NULL;
        return OK;
}//初始化单链表



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
                printf("请输入员工编号：\n");
                scanf("%s",p->num);
                printf("请输入员工姓名：\n");
                scanf("%s",p->name);
                printf("请输入员工性别：\n");
                scanf("%s",p->sex);
                printf("请输入员工出生年月：\n");
                scanf("%s",p->birth);
                printf("请输入员工学历：\n");
                scanf("%s",p->edu);
                printf("请输入员工职务：\n");
                scanf("%s",p->post);
                printf("请输入员工电话：\n");
                scanf("%s",p->tel);
                printf("请输入员工住址：\n");
                scanf("%s",p->address);
            }
    p->next=L->next;
    L->next=p;
}//头插法生成单链表



void Display(Linklist &L)
{
    Linklist p;
    for(p=L->next;p;p=p->next)
        {
            printf("编    号 ：  %s\n",p->num);
            printf("姓    名 ：  %s\n",p->name);
            printf("性    别 ：  %s\n",p->sex);
            printf("出生年月 ：  %s\n",p->birth);
            printf("学    历 ：  %s\n",p->edu);
            printf("职    务 ：  %s\n",p->post);
            printf("电    话 ：  %s\n",p->tel);
            printf("住    址 ：  %s\n",p->address);
            printf("-----------------------------------------\n");
        }
}//显示所有员工信息



int SearchNum(Linklist &L,char num[10])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->num,num)==0)
            {
                printf("编    号 ：  %s\n",p->num);
                printf("姓    名 ：  %s\n",p->name);
                printf("性    别 ：  %s\n",p->sex);
                printf("出生年月 ：  %s\n",p->birth);
                printf("学    历 ：  %s\n",p->edu);
                printf("职    务 ：  %s\n",p->post);
                printf("电    话 ：  %s\n",p->tel);
                printf("住    址 ：  %s\n",p->address);
                printf("-----------------------------------------\n");
            }
            p=p->next;
        }
        return OK;
}//编号查询



int SearchName(Linklist &L,char name[20])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->name,name)==0)
            {
                printf("编    号 ：  %s\n",p->num);
                printf("姓    名 ：  %s\n",p->name);
                printf("性    别 ：  %s\n",p->sex);
                printf("出生年月 ：  %s\n",p->birth);
                printf("学    历 ：  %s\n",p->edu);
                printf("职    务 ：  %s\n",p->post);
                printf("电    话 ：  %s\n",p->tel);
                printf("住    址 ：  %s\n",p->address);
                printf("-----------------------------------------\n");
            }
            p=p->next;
        }
        return OK;
}//姓名查询



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
            printf("编    号 ：  %s\n",p->num);
            printf("姓    名 ：  %s\n",p->name);
            printf("性    别 ：  %s\n",p->sex);
            printf("出生年月 ：  %s\n",p->birth);
            printf("学    历 ：  %s\n",p->edu);
            printf("职    务 ：  %s\n",p->post);
            printf("电    话 ：  %s\n",p->tel);
            printf("住    址 ：  %s\n",p->address);
            printf("-----------------------------------------\n");
        }
        p=p->next;
    }
    return OK;
}//姓氏查询



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
}//编号排序



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
}//姓名排序



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
}//性别排序



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
}//出生年月排序



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
}//学历排序



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
}//职务排序



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
}//电话排序



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
}//住址排序



int Alter(Linklist &L,char num[10])
{
    LNode *p;
    p=L;
    while(p)
        {
            if(strcmp(p->num,num)==0)
                {
                    printf("请输入新员工编号：\n");
                    scanf("%s",p->num);
                    printf("请输入新员工姓名：\n");
                    scanf("%s",p->name);
                    printf("请输入新员工性别：\n");
                    scanf("%s",p->sex);
                    printf("请输入新员工出生年月：\n");
                    scanf("%s",p->birth);
                    printf("请输入新员工学历：\n");
                    scanf("%s",p->edu);
                    printf("请输入新员工职务：\n");
                    scanf("%s",p->post);
                    printf("请输入新员工电话：\n");
                    scanf("%s",p->tel);
                    printf("请输入新员工住址：\n");
                    scanf("%s",p->address);
                    printf("更新成功！\n");
                }
            p=p->next;
        }
        return OK;
}//更改



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
        printf("\n删除位置不合理！\n");
    else
        {
            r->next=p->next;
            free(p);
            printf("删除成功！\n");
        }
        return OK;
}//按编号删除



//主函数
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
            printf("欢迎进入员工管理系统！\n");
            printf("-----------------------------------------\n");
            printf("1-添加员工信息\n");
            printf("2-查询员工信息\n");
            printf("3-排序员工信息\n");
            printf("4-更新员工信息\n");
            printf("5-删除员工信息\n");
            printf("6-退出\n");
            printf("请选择操作序号以回车结束:\n");
            scanf("%d",&y);
            switch(y)
            {
                case 1: CreatList(L);
                do
                    {
                        printf("-----------------------------------------\n");
                        printf("继续添加?(Y/N)\n");
                        getchar();
                        scanf("%c",&m);
                        if(m=='Y')
                            {
                                CreatList(L);
                            }
                    }
                while(m!='N');
                    break;

                case 2: printf("请输入查询方式(按编号查询请按1,按姓名查询请按2,按姓氏查询请按3)\n");
                scanf("%d",&a);
                if(a==1)
                    {
                        printf("请输入欲查询员工编号\n");
                        scanf("%s",&num);
                        printf("-----------------------------------------\n");
                        SearchNum(L,num);
                    }
                if(a==2)
                    {
                        printf("请输入欲查询员工姓名\n");
                        scanf("%s",&name);
                        printf("-----------------------------------------\n");
                        SearchName(L,name);
                    }
                if(a==3)
                    {
                        printf("请输入欲查询员工姓氏\n");
                        scanf("%s",&surname);
                        printf("-----------------------------------------\n");
                        SearchSurname(L,surname);
                    }
                    break;

                case 3: printf("请选择排序条件:1.编号2.姓名3.性别4.出生年月5.学历6.职务7.电话8.地址0.退出\n");
                scanf("%d",&a);
                if(a==1)
                    {
                        printf("按编号排序:\n");
                        printf("-----------------------------------------\n");
                        SortNum(L,num);
                    }
                if(a==2)
                    {
                        printf("按姓名排序:\n");
                        printf("-----------------------------------------\n");
                        SortName(L,name);
                    }
                if(a==3)
                    {
                        printf("按性别排序:\n");
                        printf("-----------------------------------------\n");
                        SortSex(L,sex);
                    }
                if(a==4)
                    {
                        printf("按出生年月排序:\n");
                        printf("-----------------------------------------\n");
                        SortBirth(L,birth);
                    }
                if(a==5)
                    {
                        printf("按学历排序:\n");
                        printf("-----------------------------------------\n");
                        SortEdu(L,edu);
                    }
                if(a==6)
                    {
                        printf("按职务排序:\n");
                        printf("-----------------------------------------\n");
                        SortPost(L,post);
                    }
                if(a==7)
                    {
                        printf("按电话排序:\n");
                        printf("-----------------------------------------\n");
                        SortTel(L,tel);
                    }
                if(a==8)
                    {
                        printf("按住址排序:\n");
                        printf("-----------------------------------------\n");
                        SortAddress(L,address);
                    }
                    break;

                case 4: printf("请输入欲更改员工编号:\n");
                getchar();
                scanf("%s",&num);
                Alter(L,num);
                break;

                case 5: printf("请输入欲删除员工编号:\n");
                getchar();
                scanf("%s",&num);
                Delete(L,num);
                break;

                case 6: x=0;
                break;

                default:
                    printf("请按照提示输入正确序号！！！\n");
                    break;
            }

        }

}
