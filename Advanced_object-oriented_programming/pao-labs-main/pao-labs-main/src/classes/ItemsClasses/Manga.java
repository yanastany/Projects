package classes.ItemsClasses;

import classes.Author.Author;

public class Manga extends Item {
    protected Author author;
    protected int chapter;

    public Manga(){}

    public Manga(int cota, int nrex, String title, Author author, int chapter) {
        super(cota, nrex, title);
        this.author = author;
        this.chapter = chapter;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }

    public int getChapter() {
        return chapter;
    }

    public void setChapter(int chapter) {
        this.chapter = chapter;
    }

    public String toCSV(){
        return cota +
                "," + nrex+
                "," + title+
                "," + author.getName()+
                "," + chapter;
    }
}
