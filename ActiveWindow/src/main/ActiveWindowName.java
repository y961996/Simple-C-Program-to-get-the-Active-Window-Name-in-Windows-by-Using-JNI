package main;

public class ActiveWindowName {

	public native String getActiveWindowName();
	
	public static void main(String[] args) {
		System.loadLibrary("ActiveWindow");
		ActiveWindowName test = new ActiveWindowName();
		System.out.println(test.getActiveWindowName());
	
		int a = 0;
		while(a < 100) {
			try {
				System.out.println(test.getActiveWindowName());
				a++;
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
