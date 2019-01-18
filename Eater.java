public interface Eater {
        /**
        * Bergerak mengejar suatu objek.
        * @param Objects
        * @return 
        */
	public int pursue(final List<AquariumObject> Objects);
        /**
         * Mengenai suatu objek lalu "mengonsumsinya"(contoh ikan makan pellet).
         * @param Objects
         * @param indeks
         * @return 
         */
	public int consume(List<AquariumObject> Objects, final int indeks);
}
