package classes.Generice;

import java.io.PrintWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class citire {
    public static citire instance;
    private citire(){}

    public static citire getInstance(){
        if (instance==null){
            synchronized (citire.class){
                if (instance==null){
                    instance =new citire();
                }
            }
        }
        return instance;
    }


    public <T> List<T> read(String path, Class<T> type) throws Exception {
        List<T> records = new ArrayList<T>();
        Constructor<T> constructor = type.getDeclaredConstructor();
        Field[] coloana = type.getDeclaredFields();
        constructor.setAccessible(true);
        for (Field col : coloana) {
            col.setAccessible(true);
        }
        for (String line : Files.readAllLines(Paths.get(path))) {
            T record = constructor.newInstance();
            String[] values = line.split(",");
            for (int i = 0; i < values.length; i++) {
                setField(record, coloana[i], values[i]);
            }
            records.add(record);
        }
        return records;
    }

    public <T> void write(List<T> records,String path) throws Exception {
        Field[] fields = records.get(0).getClass().getDeclaredFields();
        for (Field field : fields) {
            field.setAccessible(true);
        }

        try (PrintWriter writer = new PrintWriter(path)) {
            for (T record : records) {
                for (int i = 0; i < fields.length - 1; i++) {
                    Object value = fields[i].get(record);
                    if (value != null) {
                        writer.print(value);
                    }
                    writer.print(",");
                }
                Object value = fields[fields.length - 1].get(record);
                if (value != null) {
                    writer.println(value);
                }
            }
        }
    }


    private void setField(Object object, Field col, String nume) throws Exception {
        if (nume.isEmpty()) {
            return;
        }
        Object value = null;
        if (String.class.equals(col.getType())) {
            value = nume;
        } else {
            String name=Character.toUpperCase(col.getType().getSimpleName().charAt(0)) + col.getType().getSimpleName().substring(1);
            Class<?> type = Class.forName("java.lang." + name + (int.class.equals(col.getType()) ? "eger" : ""));
            Method method = type.getDeclaredMethod("parse" + name, String.class);
            value = method.invoke(null, nume);
        }
        col.set(object, value);
    }




}
