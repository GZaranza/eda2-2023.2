

#define less(a,b) (a<b)
#define lesseq(a,b) (a<=b)
#define exch(a,b) {int t; t=a;a=b;b=t;}
#define cmpexch(a,b) {if(less(a,b)) exch(a,b)}
#define cmpeqexch(a,b) {if(lesseq(a,b)) exch(a,b)}