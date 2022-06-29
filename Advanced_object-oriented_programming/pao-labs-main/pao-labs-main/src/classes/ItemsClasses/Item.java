package classes.ItemsClasses;

public class Item {
    protected int cota;
    protected int nrex; //numar exemplare
    protected String title;
    protected static int count = 0;
    protected int id=0;

    public Item(){}

    public Item(int cota, int nrex, String title) {
        this.cota = cota;
        this.nrex = nrex;
        this.title = title;
        this.id = count++;
    }

    public int getCota() {
        return cota;
    }

    public void setCota(int cota) {
        this.cota = cota;
    }

    public int getNrex() {
        return nrex;
    }

    public void setNrex(int nrex) {
        this.nrex = nrex;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public static int getCount() {
        return count;
    }

    public int getId() {
        return id;
    }



}
