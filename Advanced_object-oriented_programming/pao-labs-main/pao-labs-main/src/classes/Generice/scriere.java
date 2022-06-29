package classes.Generice;

import java.io.PrintWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class scriere {
    public static scriere instance;
    private scriere(){}

    public static scriere getInstance(){
        if (instance==null){
            synchronized (scriere.class){
                if (instance==null){
                    instance =new scriere();
                }
            }
        }
        return instance;
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


    




}
