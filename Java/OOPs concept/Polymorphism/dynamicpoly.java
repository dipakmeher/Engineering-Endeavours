class A{
	int i=10;
	public void m1(){
		System.out.println(" This is class A.");
	}
}
class B extends A{
	int i=20;
	public void m1(){
		System.out.println(" This is class B.");

	}
}
class C extends B{
	int i=30;
	public void m1(){
		System.out.println(" This is class C.");
	}
}
class dynamicpoly{
	public static void main(String args[]){
		A a = new A();
		A b = new B();
		A c = new C();

		System.out.println(" This is method.\n");
		a.m1();
		b.m1();
		c.m1();
		System.out.println();
		System.out.println(" This is variable.\n");
		System.out.println(""+a.i);
		System.out.println(""+b.i);
		System.out.println(""+c.i);
	}
}