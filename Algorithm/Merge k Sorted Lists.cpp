#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

auto comp = [](ListNode* &a, ListNode* &b) -> bool { return a->val > b->val;  };

class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		// Maybe we should use an priority queue...
		priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> list_node_que_queue(comp);
		auto result_list_start = new ListNode(-1);
		auto result_list_end = result_list_start;

		for_each(lists.begin(), lists.end(), [&list_node_que_queue](ListNode* list_start)
		{
			if (list_start)
				list_node_que_queue.push(list_start);
		});

		//
		while (!list_node_que_queue.empty())
		{
			auto list_start = list_node_que_queue.top();
			list_node_que_queue.pop();
			result_list_end->next = new ListNode(list_start->val);
			result_list_end = result_list_end->next;

			list_start = list_start->next;
			if (list_start)
				list_node_que_queue.push(list_start);
		}

		auto result_list = result_list_start->next; // Get the result.
		free(result_list_start); // Free the extra memory used.
		return result_list;
	}
};

int main()
{
	auto solution = Solution();
	auto a = new ListNode(1);
	auto c = new ListNode(3);
	a->next = c;

	auto b = new ListNode(2);

	std::vector<ListNode*> container;
	container.push_back(a);
	container.push_back(b);

	auto solution_list = solution.mergeKLists(container);

	while(solution_list)
	{
		std::cout << solution_list->val << std::endl;
		solution_list = solution_list->next;
	}

	getchar();
}