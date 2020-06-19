int Solution::solve(vector<vector<int> > &A) 
{
    int R=A.size();
    if(R==0)
        return 0;
    int C=A[0].size();

    int hist[R+1][C+1];
    int i,j,k;
    
    for(i=0;i<C;i++)
    {
        hist[0][i]=A[0][i];
        for(j=1;j<R;j++)
            hist[j][i]=(A[j][i]==0)?0:hist[j-1][i]+1;
    }
    for(i=0;i<R;i++)
    {
        int count[R+1]={0};

        for(j=0;j<C;j++)
        {
            count[hist[i][j]]++;
        }
        
        int col_no=0;
        for(j=R;j>=0;j--)
        {
            if(count[j]>0)
            {
                for(k=0;k<count[j];k++)
                {
                    hist[i][col_no]=j;
                    col_no++;
                }
            }
        }
    }
    int curr_area,max_area=0;
    for(int i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            curr_area=(j+1)*hist[i][j];
            if(max_area<curr_area)
                max_area=curr_area;
        }
    }
    return max_area;
}
