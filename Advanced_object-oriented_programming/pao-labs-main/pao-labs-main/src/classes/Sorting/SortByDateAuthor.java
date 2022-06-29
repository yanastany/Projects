package classes.Sorting;

import classes.Author.Author;
import classes.Reader.Reader;

import java.util.Comparator;

public class SortByDateAuthor implements Comparator<Author> {

    public int compare(Author a, Author b) {
        return Integer.parseInt(a.getDataString()) - Integer.parseInt(b.getDataString());
    }
}

