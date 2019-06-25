/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copy(RandomListNode *head, map<RandomListNode *, RandomListNode *> & oldnewMap){
        // visited nodes are put in: oldnewMap
        if(!head) return NULL;
        if(oldnewMap.find(head) == oldnewMap.end()){
            RandomListNode * new_head = new RandomListNode( head->label );
            oldnewMap.insert( make_pair(head, new_head) );
            new_head -> next   = copy( head->next, oldnewMap);
            new_head -> random = copy( head->random, oldnewMap);
            return new_head;
        }else{
            return oldnewMap[head];
        }
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        map<RandomListNode *, RandomListNode *> oldnewMap;
        return copy(head, oldnewMap);
    }
};
