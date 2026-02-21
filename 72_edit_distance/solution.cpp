class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(),n2 = word2.size();
        if(n1==0){
            if(n2==0)return 0;
            return n2;
        }
        if(n2==0){
            return n1;
        }
        vector<vector<int>> invariant(n1+1, vector<int>(n2+1, 0));
        // The source prefix can be transformed into empty string by dropping all characters.
        for(int i=1;i<=n1;i++){
            invariant[i][0] = i;
        }
        // The target prefix can be achieved from the empty source string by adding all the characters.
        for(int j=1;j<=n2;j++){
            invariant[0][j] = j;
        }

        for(int j=1;j<=n2;j++){
            for(int i=1;i<=n1;i++){
                int subs = 0;
                // since the index is 1 bases. We compare index i-1 and j-1;
                if(word1[i-1] != word2[j-1]) {
                    subs = 1;
                }
                invariant[i][j] = min(
                    invariant[i-1][j]+1, // deletion.
                    min(
                        invariant[i][j-1]+1, // insertion
                        invariant[i-1][j-1]+subs // subs
                    )
                );
            }
        }
        return invariant[n1][n2];

    }
};
