package classes.Audit;

import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeFormatterBuilder;

public class AuditService {
    final DateTimeFormatter DateFor = DateTimeFormatter.ofPattern("dd-MM-yyyy : HH:mm:ss");
    FileWriter r;

    public void actiuneaudit(String action) throws IOException {
        r.append(action);
        r.append(", ");
        r.append(DateFor.format(LocalDateTime.now()));
        r.append(" - ora la care a avut loc actiunea");
        r.append("\n");
        r.flush();
    }
    public AuditService() {
        try{
            this.r = new FileWriter("src/classes/Audit/audit.csv");
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }

}
