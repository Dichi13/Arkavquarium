public class ElmtList<T> {
	private T value;
	private ElmtList<T> next;

	public ElmtList(T val) {
		value = val;
		next = null;
	}
	public final T getValue() {
		return value;
	}
	public final ElmtList<T> getNext() {
		return next;
	}
	public final void setNext(final ElmtList<T> element) {
		next = element;
	}
}