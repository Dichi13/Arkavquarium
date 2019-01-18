public class List<T> {
	private ElmtList<T> head;

	public List() {
		head = null;
	}

	public int find(T element) {
		ElmtList<T> p = head;
		int i = 0;

		while (p != null && p.getValue() != element) {
			p = p.getNext();
			i += 1;
		}

		if (p.getValue() == element) {
			return i;
		} else {
			return -1;
		}
	}

	public boolean isEmpty() {
		return (head == null);
	}

	public void add(T element) {
		ElmtList<T> p = head;
		ElmtList<T> temp = new ElmtList<T>(element);

		if (p == null) {
			p = temp;
			head = p;
		} else {
			while (p.getNext() != null) {
				p = p.getNext();
			}
			p.setNext(temp);
		}
	}

	public void remove(T element) {
		ElmtList<T> p = head;
		ElmtList<T> pDel;

		if (p.getValue() == element) {
			head = p.getNext();
			p = null;
		} else {
			while (p.getNext().getValue() != element && p.getNext() != null) {
				p = p.getNext();
			}
			if (p.getNext().getValue() == element) {
				pDel = p.getNext();
				p.setNext(p.getNext().getNext());
				pDel = null;
			}
		}
	}

	public T get(int index) {
		int i = 0;
		ElmtList<T> p = head;

		while(i != index) {
			p = p.getNext();
			i += 1;
		}

		return p.getValue();
	}

	public int length() {
		int i = 0;
		ElmtList<T> p = head;

		while (p != null) {
			p = p.getNext();
			i += 1;
		}

		return i;
	}

	public static void main(String[] args) {
		List<Integer> a = new List<Integer>();

		Integer p = new Integer(1);
		Integer o = new Integer(2);
		Integer i = new Integer(3);

		a.add(p);
		a.add(o);
		a.add(i);

		System.out.println(a.length());
		System.out.println(a.get(1));
		a.remove(o);
		System.out.println(a.length());
		System.out.println(a.get(1));
	}
}