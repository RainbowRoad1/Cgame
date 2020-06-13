main(){int m[900]={4},z[3]={0},l=3,c='D',C,i,*p;srand(malloc(!system(
"mode con:cols=60 lines=30")));f:for(;m[i=rand()%900];);for(m[i]=-1,++l;
1;_sleep(100)){for(m[z[2]]=l+1,system("cls"),i=0;i<900;i++)_cputs(m[i]>0
&&--m[i]?"()":m[i]?"00":"  ");if(kbhit())C=getch()&95,C-65&&C-68&&C-83&&
C-87||((C^c)&20)-4&&(c=C);p=z+!!(c&16),*p+=c/6&1?1:-1,*p=(*p+30)%30;if(m
[z[2]=*z+z[1]*30]<0)goto f;if(m[z[2]]>1)break;}}

/*
使用gcc编译通过(MinGW)(gcc version 8.2.0)
虽然报错挺多的，但编译能通过???
不管了,能生成能运行就行
总共406字符,每行80个还是多6个,就干脆写6行了...
*/
