package classes.ItemsClasses;

public class CD extends Item {

    protected String type;

    public CD(){}

//    public CD(int cota, int nrex, String title, String type) {
//        super(cota, nrex, title);
//        this.type = type;
//    }
    public CD(int cota, int nrex, String title, String type) {

        this.cota=cota;
        this.nrex=nrex;
        this.title=title;
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
    public String toCSV(){
        return cota +
                "," + nrex+
                "," + title+
                "," + type;
    }
}
