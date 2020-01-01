public class MyClass {
    public static void main(String args[]) {
      MyClas obj = new MyClas(6);
      obj.union(1,5, "2019-08-14 18:00:00");
      obj.union(2,4, "2019-08-14 18:00:01");
      obj.union(1,3, "2019-08-14 18:00:02");
      obj.union(5,2, "2019-08-14 18:00:03");
      obj.union(0,3,"2019-08-14 18:00:04");
      obj.union(2,1,"2019-08-14 18:00:05");
    }
}
