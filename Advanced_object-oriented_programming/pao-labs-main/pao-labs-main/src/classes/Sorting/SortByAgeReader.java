package classes.Sorting;

import classes.Reader.Reader;

import java.util.Comparator;

public class SortByAgeReader implements Comparator<Reader> {

    public int compare(Reader a, Reader b) {
        return a.getAge() - b.getAge();
    }
}
