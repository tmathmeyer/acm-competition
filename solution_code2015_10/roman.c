#define _DEFAULT_SOURCE
#include <stdio.h>
#define l(x) ((((x)>='A')&&((x)<='Z'))?((x)-'A'):((x)-'a'))
#define a(x) (argc[1][(x)])
#define lv(x) (values[(x)])
#define before(x, a, b) (fcp[(x)-'a']=(a),scp[(x)-'a']=(b))
#define value(c, v) (values[(c)-'a']=(v))
int main(int argv, char **argc) {
    int res=0,nmf=0,ct=0,c=0,max=0,b=99999999;
    int fcp[26]={0},scp[26]={0},values[26]={0};
    size_t q;

    /* FILL IN PRECEDENCE HERE */
    /* USE LOWERCASE */
    before('i', 'v', 'x'); // i can precede v or X
    before('x', 'l', 'c'); // x can precede l or c
    before('c', 'd', 'm'); // c can precede m or m

    /* FILL IN VALUE HERE */
    value('i', 1);
    value('v', 5);
    value('x', 10);
    value('l', 50);
    value('c', 100);
    value('d', 500);
    value('m', 1000);
    max = ('m');

    while(getline(argc+1, &q, stdin) != -1) {
        while(a(c)&&a(c)!='\n') {
            if(lv(l(a(c)))>b)
                return printf("%c\n", a(c)), 1;
            int v = lv(l(a(c)));
            if(!a(c+1)||(v>=lv(l(a(c+1)))))res+=(v);
            else if(((fcp[l(a(c))]==l(a(c+1))+'a')
                   ||(scp[l(a(c))]==l(a(c+1))+'a'))&&(v<lv(l(a(c+1))))){
                res+=(lv(l(a(c+1)))-v);
                if(lv(l(a(c+1)))>b)return printf("%c\n",a(c+1)),1;
                b=(b>(v-1)?v-1:b);
                if(c>0&&!fcp[l(a(c+1))]&&l(argc[1][c-1])==l(a(c+1)))
                    return printf("%c\n",a(c+1)),1; // sandwich
                c++;
                if (nmf==l(a(c)))ct--;
            }
            else return printf("%c\n", a(c+1)), 1;
            if(nmf==l(a(c))) {
                if(l(a(c))!=l(max)&&ct==(fcp[l(a(c))]?3:1))
                    return printf("%c\n",l(a(c))+'A');
            } else nmf=l(a(c)),ct=0;
            if(a(c))c++;
            ++ct,b=b>v?v:b;
        }
        printf("%i\n",res),c=res=ct=nmf=0,b=999999999;
    }
}
