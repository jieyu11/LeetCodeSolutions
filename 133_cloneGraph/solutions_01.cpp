/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // map<UndirectedGraphNode *, UndirectedGraphNode *> & oldNewVisited
    // key: old UndirectedGraphNode *, to track if the node has already been visited
    // value: new UndirectedGraphNode *, if the old is already visited, then return the corresponding new node.
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> & oldNewVisited) {
        // check if the node is already visited, if not, create a new node as copy
        if(oldNewVisited.find( node ) == oldNewVisited.end()){
            UndirectedGraphNode *n_node = new UndirectedGraphNode( node->label );
            oldNewVisited.insert( make_pair(node, n_node) ); // old -> new mapping
            // then put all the cloned neighbors into the neighbors list
            for (UndirectedGraphNode *node_nb : node->neighbors ) n_node->neighbors.push_back( clone(node_nb, oldNewVisited ) );
            // return the parent node, all the neighbors are copied and inserted.
            return n_node;
        }else{
            return oldNewVisited[ node ]; // use the old as key to find the new node, return it.
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode *> oldNewVisited;
        return clone(node, oldNewVisited);
    }
};
