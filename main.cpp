#include <iostream>
#include <deque>
using namespace std;

const int N = 1e5+5;

int q, x;
char op[10];
deque<int> dq;

int main(){
    scanf_s("%d", &q);
    while(q--){
        scanf_s("%s", op);
        if(op[0] == 't'){   //toFront
            scanf_s("%d", &x);
            dq.push_front(x);
        }else if(op[0] == 'p'){ //push_back
            scanf_s("%d", &x);
            dq.push_back(x);
        }else if(op[0] == 'r'){ //reverse
            //TODO
            reverse(dq.begin(), dq.end());
        }else if(op[0] == 'b'){ //back
            if(dq.size() == 0)
                printf("No job for Ada?\n");
            else{
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }else if(op[0] == 'f'){ //front
            if(dq.size() == 0)  printf("No job for Ada?\n");
            else{
                printf("%d\n", dq[0]);
                dq.pop_front();
            }
        }
    }
    return 0;
}