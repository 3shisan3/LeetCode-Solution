/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int len1 = 1;//记录l1的链表长度
		int len2 = 1;//记录l2的链表长度
		ListNode* p = l1; 
		ListNode* q = l2;
		while (p->next != NULL)//获取l1的长度
		{
			len1++;
			p = p->next;
		}
		while(q->next != NULL)//获取l2的长度
		{
			len2++;
			q = q->next;
		}
		//短的链表进行补零
		if (len1 > len2)
		{
			for (int i = 1; i <= len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
		}
		else
		{
			for (int i = 1; i <= len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}
		}
		p = l1;
		q = l2;

		bool flag = false;//记录一个进位标志
		ListNode* l3 = new ListNode(0); //创建一个存放结果的链表
		ListNode* w = l3;
		int i = 0;//临时变量存储记录相加结果
		while (p != NULL && q != NULL)
		{
			i = flag + p->val + q->val;
			w->next = new ListNode(i % 10);
			flag = (i >= 10) ? true : false;
			w = w->next;
			p = p->next;
			q = q->next;
		}
		if (flag)
		{
			w->next = new ListNode(1);
			w = w->next;
		}

		return l3->next;
	}
};
