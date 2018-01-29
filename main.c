//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int data;
//    struct node *rear;
//    struct node *next;
//}NODE;
//
//int main() {
//    int n, i ,m, k, n1, m1=0, m2=0;
//    int total = 1;
//
//    NODE *head;
//    NODE *p;
//    NODE *q1;
//    NODE *q2;
//
//    scanf("%d,%d,%d",&n,&k,&m);
//    if(n<1||k<1||m<1){
//        printf("n,m,k must bigger than 0.\n");
//    } else if(k>n){
//        printf("k should not bigger than n.\n");
//    } else {
//        head = (NODE*)malloc(sizeof(NODE));
//        head->next = head;
//        head->data = 1;
//
//        for(i=0;i<n-1;i++){
//            p = (NODE*)malloc(sizeof(NODE));
//            p->data = n - i;
//            p->next = head->next;
//            head->next = p;
//            p->rear = head;
//            p->next->rear = p;
//        }
//        n1 = n;
//        for(i = 1, q1 = head, q2 = head; i < k; i++){
//            q1 = q1->next;
//            q2 = q2->next;
//        }
//        for(;;){
//            if(q1->data != -1){
//                m1++;
//            }
//            if(q2->data != -1){
//                m2++;
//            }
//            if(m1 == m && m2 == m){
//                if(q1->data == q2->data){
//                    if(total == n)
//                        printf("%d,\n",q1->data);
//                    else
//                        printf("%d,",q1->data);
//                    total++;
//                    n1--;
//                    m1 = 0;
//                    m2 = 0;
//                    q1->data = -1;
//                } else {
//                    printf("%d",q1->data);
//                    if(total == n - 1)
//                        printf("-%d,\n",q2->data);
//                    else
//                        printf("-%d,",q2->data);
//                    total+=2;
//                    n1-=2;
//                    m1=0;
//                    m2=0;
//                    q1->data = -1;
//                    q2->data = -1;
//                }
//            }
//            if(n1 == 0)
//                break;
//            q1 = q1->next;
//            q2 = q2->rear;
//        }
//    }
//
//    return 0;
//}