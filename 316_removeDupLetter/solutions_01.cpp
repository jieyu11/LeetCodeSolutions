class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if(n==0) return "";
        vector<int> counts(26,0);
        for(char c : s){
            int id = c - 'a';
            counts[id]++;
        }
        vector<bool> visited(26,false);
        
        string result = ""; result += s[0];
        int id0 = s[0] - 'a';
        counts[id0]--;
        visited[id0] = true;
        for(int i=1; i<n; i++){
            int id = s[i] - 'a';
            counts[id]--; // record how many in the later string
            if(visited[id]) continue;
            
            // !!! main idea:
            // if the current character is smaller than the previous one
            // and the previous one appears later, then remove the revious one!
            int idpre = -1;
            if(result != "") idpre = result.back() - 'a';
            while(id < idpre && counts[idpre]){
                result.pop_back();
                visited[idpre] = false;
                if(result != "") idpre = result.back() - 'a';
                else idpre = -1;
            }
            result += s[i];
            visited[id] = true;
        }
        return result;
    }
};
