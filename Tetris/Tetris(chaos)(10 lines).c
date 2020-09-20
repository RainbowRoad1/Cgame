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
使用gcc编译通过(MinGW)(gcc version 8.2.0)
总字符709个, 比上个版本少了100多个字符
*/
