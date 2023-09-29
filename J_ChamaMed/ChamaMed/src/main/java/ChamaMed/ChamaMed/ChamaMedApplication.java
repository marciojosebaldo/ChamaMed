package ChamaMed.ChamaMed;

import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortTimeoutException;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.io.IOException;
import java.io.InputStream;

@SpringBootApplication
public class ChamaMedApplication {

    public static void main(String[] args) {
        SpringApplication.run(ChamaMedApplication.class, args);
        Arduino();
    }

    private static final String nomePortaArduino = "COM4";
    private static final int baudRate = 9600;

    public static void Arduino() {
        SerialPort serialPort = SerialPort.getCommPort(nomePortaArduino);
        serialPort.setBaudRate(baudRate);

        if (!serialPort.openPort()) {
            System.err.println("Falha ao conectar com a porta serial");
            return;
        }

        InputStream inputStream = serialPort.getInputStream();
        byte[] buffer = new byte[1024]; // Tamanho do buffer, ajuste conforme necessário

        try {
            while (true) {
                int bytesRead = inputStream.read(buffer);
                if (bytesRead > 0) {
                    int[] estados = new int[bytesRead];
                    for (int i = 0; i < bytesRead; i++) {
                        estados[i] = buffer[i];
                    }

                    for (int estado : estados) {
                        if (estado == 1) {
                            System.out.println("Porta em estado HIGH");
                        } else if (estado == 0) {
                            System.out.println(("Porta em estado LOW"));
                        }
                    }
                }
            }
        } catch (SerialPortTimeoutException e) {
            System.err.println("Timeout na leitura da porta serial");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            serialPort.closePort();
        }
    }
}