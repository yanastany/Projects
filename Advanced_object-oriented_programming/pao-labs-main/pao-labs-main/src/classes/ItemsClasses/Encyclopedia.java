package classes.ItemsClasses;

import classes.Author.Author;

public class Encyclopedia extends Item {
    protected Author author;
    protected String type;

    public Encyclopedia(){}

    public Encyclopedia(int cota, int nrex, String title, Author author, String type) {
        super(cota, nrex, title);
        this.author = author;
        this.type = type;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
