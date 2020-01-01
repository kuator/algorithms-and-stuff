public class MyClas {
    private int[] a;
    private int[] size;
    int N=0;
    public MyClas(int n){
        N=n;
        a = new int[n];
        size = new int[n];
        for(int i=0;i<n;i++){
            a[i]=i;
            size[i]=1;
        }
    }
    private int root(int x){
        while(x != a[x]){
            x=a[x];
        }
        return x;
    }
    public boolean connected(int p, int q){
        return root(p)==root(q);
    }
    public void union(int p,int q, String timestamp){
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(size[i] < size[j]){
            a[i] = j;
            size[j]+=size[i];
            if(size[j]==N){
                System.out.println("All Members are connected at Timestamp"+ timestamp);
            }
        }
        else{
            a[j] = i;
            size[i]+=size[j];
            if(size[i]==N){
                System.out.println("All Members are connected at Timestamp"+ timestamp);
            }
        }
    }

}
