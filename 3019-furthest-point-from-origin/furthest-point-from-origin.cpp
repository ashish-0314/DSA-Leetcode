class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcnt = 0 , rcnt = 0  , ccnt = 0;
        for(int i =0 ; i < moves.size() ; i++){
            if(moves[i]=='_') ccnt++;
            else if(moves[i]=='L') lcnt++;
            else rcnt++;
        }
        if(lcnt==0 && rcnt==0) return ccnt;
        else if(lcnt>rcnt) return lcnt+ccnt-rcnt;
        else return rcnt+ccnt-lcnt;
    }
};