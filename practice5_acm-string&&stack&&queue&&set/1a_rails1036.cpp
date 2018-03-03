
#include<stack>
#include<iostream>

using namespace std;

int main()
{
		int n;
		while(cin >> n && n != 0)
		{
			while(1)
			{
				int train[n];
				for(int i = 0; i < n; i++ )
				{
					cin >> train[i];
					if(train[0] == 0)break;
				}
				if(train[0] == 0)break;

				int inStack =0;
				stack<int> stk;
				bool res =true;

				for(int i = 0; i < n; i++ )
				{
				    //ͨ���ѱ��Լ�С�Ķ�ѹ��ȥ�����ԱȺ����˳���Ƿ����ջ�ĵ���
					if(train[i] >inStack)
					{
						while(inStack< train[i]){
                            inStack++;
                            stk.push(inStack);
						}
					}
					if(stk.top() != train[i]){
                        res = false;
					}
					else{
                        stk.pop();
					}
				}
				if(res) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
			cout<<endl;
		}
	return 0;
}
