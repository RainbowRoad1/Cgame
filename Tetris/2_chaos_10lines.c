#define G(C)for(C,i=n[T];j=X+i%4,k=Y+i/4%4,i;i>>=4)
int W=10,H=25,S,i,j,k,c,d=0,X=0,Y=0,T=0,*m,n[]={51264,12816,21520,21520,25872,
34113,21537,38208,25921,38481,38484,38209,25922,43345,34388,38160,25920,38177,
42580,38993};M(int*v,int l){G(*v+=l)(j<0||j>=W||k>=H||m[k*W+j])&&(c=0);return 
c?1:(*v-=l,v==&Y&&(c=-1));}main(){for(srand(m=calloc(S=W*H,4));c-27;_sleep(50)
,system("cls")){G(c=kbhit()?getch()&95:1)m[k*W+j]=0;c^87||(i=T<8?1:3,M(&T,T&i^
i?1:-i));c^65&&c^68||M(&X,c&1?-1:1),c^83||M(&Y,1);G(++d-10||(d=0,c=1,M(&Y,1)))
m[k*W+j]=1;for(;i<S;++i%W||puts("|"))printf(m[i]?"[]":"  ");if(c==-1&&!(Y<1&&(
c=27),T=rand()%19,Y=X=0))for(j=W,i=S-1;j-=m[i],i>=W;i--%W||(j=W))for(k=i+W;!j
&&(--k>=W||!(i+=W));m[k]=m[k-W]);}}

/*
11行俄罗斯方块, 709字符(不包含换行符), 在1行80字符限制下仅可能减少代码;
AD移动, S下坠, W旋转, 某一行填满方块则消行, 当方块堆到顶层或按下Esc键时游戏结束;
可自定义地图尺寸(W, H)
比行数没意思, 较真还得看字符量(雾)
此处使用gcc编译通过, vs需要屏蔽4996号错误, 加上下面一行代码
#pragma warning(disable:4996)
于2020.9.20上传, 2020.10.2补充说明

下面是之前的说明:

使用gcc编译通过(MinGW)(gcc version 8.2.0)
总字符709个, 比上个版本少了100多个字符
*/