// // package dsa;

// import java.util.Scanner;
// import java.io.*;

// /**
//  * Node
//  */
// /**
//  * Stack
//  */
// public class Stack {
//   class Node {
//     int data;
//     Node next;
//     public Node(int data) {
//       this.data = data;
//     }
//   }

//   public Node head;

//   public void push(int value) {
//     Node newNode = new Node(value);
//     newNode.next = this.head;
//     this.head = newNode;
//     System.out.println("ok");
//   }

//   public void pop() {
//     System.out.println(head.data);
//     this.head = this.head.next;
//   }

//   public int back() {
//     System.out.println(head.data);
//     return head.data;
//   }

//   public int size() {
//     int cnt = 0;
//     Node tmp = this.head;
//     while (tmp != null) {
//       tmp = tmp.next;
//       cnt = cnt + 1;
//     }
//     System.out.println(cnt);
//     return cnt;
//   }

//   public void clear() {
//     this.head = null;
//     // while (this.head != null) {
//     //   Node tmp = this.head;
//     //   this.head = tmp.next;
//     //   tmp.next = null;
//     // }
//     System.out.println("ok");
//   }

//   public static void main(String[] args) throws IOException{
//     Stack stack = new Stack();
//     BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//     String input;
//     do {
//       input = reader.readLine();
//       String[] parts = input.split(" ");
//       String method = parts[0];
//       if (parts.length == 2) {
//         int value = Integer.parseInt(parts[1]);
//         if (method.equals("push")) 
//           stack.push(value);
//       }
//       else if (parts.length == 1) {
//         if (method.equals("pop")) 
//           stack.pop();
//         if (method.equals("clear")) 
//           stack.clear();
//         if (method.equals("size")) 
//           stack.size();
//         if (method.equals("back")) 
//           stack.back();
//       }
//     } while (!input.equals("exit"));
//     System.out.println("bye");
//     reader.close();
//     // scanner.close();
//   }
// }

import java.util.*;

//import java.io.*;

 

public class Main

{

  public static void main(String[] args) //throws IOException

  {

    Stack<Integer> s = new Stack<Integer>();  

    //Scanner con = new Scanner(new FileReader ("6122.in"));

    Scanner con = new Scanner(System.in);

 

    while(true)

    {

      String str = con.next();

      if (str.equals("push"))

      {

        int n = con.nextInt();

        s.push(n);

        System.out.println("ok");       

      } else

      if (str.equals("pop"))

      {

        System.out.println(s.pop());     

      } else

      if (str.equals("back"))

      {

        System.out.println(s.peek());    

      } else

      if (str.equals("size"))

      {

        System.out.println(s.size());    

      } else

      if (str.equals("clear"))

      {

        s.clear();

        System.out.println("ok");       

      } else       

      {

        System.out.println("bye"); 

        break;

      }

    }

    con.close();

  }

}
