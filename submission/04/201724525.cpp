#include "timebomb.h"    // 0. 반드시 포함 
#include <math.h>
#include <list>
#include <iterator>


int main( ) {
	int N, result, t ;
        box_ready( ) ;     // 1. 제일 먼저 호출해야 함. 
        N = box_size( ) ;   // 2. 갯수 확인.
		std::list<int> A;
		std::list<int> B;
		std::list<int> Temp;
		std::list<int> B2;
		std::list<int>::iterator iter;
		std::list<int>::iterator iter2;
		
		std::list<std::list<int> >::iterator iterE;
		
//		std::list<list> TTemp;
		std::list<std::list<int> > Enemylist;
		int tem = 0;
		int i = 0;
		
		i = 1;
		while (i<N){
			result = box_comp(i,i+1);
			if (result == -1){
				A.push_back(i+1);
				B.push_back(i);
				
				
			}
			else if(result == 1){
				B.push_back(i+1);
				A.push_back(i);
			}
			Enemylist.push_back({i+1});
			Enemylist.push_back({i});
			i = i+2;
		}
		if (i==N){
			A.push_back(i);
			tem = 1;
			Enemylist.push_back({});
		}
		i=0;
		//1~8 ->Enemy
		////////////////////////////////////////////////////////////////////////////////////////////////////////

		while(A.size()>1){
			while (i<A.size()-1){
				iterE = Enemylist.begin();
				iter = A.begin();
				iter2 = B.begin();
				int j=0;
				while(j<i){
					iter++;
					iter2++;
					j = j+1;
				}
				int a = *iter;
				iter++;
				int b = *iter;
				result = box_comp(a,b);
				if (result == -1){
					B.erase(iter2);
					iter--;
					A.erase(iter);
					j=1;
					while (j<b){
						iterE++;
						j = j+1;	
					}
					(*iterE).push_back(a);
					
				}
				else if(result == 1){
					iter2++;
					B.erase(iter2);
					A.erase(iter);
					j=1;
					while (j<a){
						iterE++;
						j = j+1;	
					}
					(*iterE).push_back(b);
					
				}
				i = i+1;
				j=0;
				
			
			
			}
			i=0;
			
			
		}
		iter = A.begin();
		iterE = Enemylist.begin();
		i=1;
		
		while (i<*iter){
			
			iterE++;
			i = i+1;
		}
		Temp = *iterE;
		i=0;
		
		while(Temp.size()>1){
			
			while (i<Temp.size()-1){
				
				iter = Temp.begin();
				
				int j=0;
				while(j<i){
					iter++;
					j = j+1;
				}
				int a = *iter;
				iter++;
				int b = *iter;
				result = box_comp(a,b);
				if (result == -1){
					iter--;
					Temp.erase(iter);
				}
				else if(result == 1){
					Temp.erase(iter);
					
				}
				i = i+1;	
			}
			i=0;	
		}
		
		iter = Temp.begin();
		t = *iter;
        //result = box_comp( i, j ) // 무게 비교 작업
         	
         
        box_report( t ) ;  // 정답 보고, 종료됨 
} // end of main( )
