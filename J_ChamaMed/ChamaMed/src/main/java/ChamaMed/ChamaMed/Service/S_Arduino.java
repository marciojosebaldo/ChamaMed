package ChamaMed.ChamaMed.Service;

import com.fazecast.jSerialComm.SerialPort;

import java.io.IOException;
import java.io.InputStream;

public class S_Arduino {

    private static final String nomePortaArduino = "";
    private static final int baudRate = 9600;
    private static final int tempoEspera = 200;

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
                    String dadosLidos = new String(buffer, 0, bytesRead);
                    // Processar os dados recebidos (dadosLidos)
                    System.out.println("Dados lidos: " + dadosLidos);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            serialPort.closePort();
        }
    }
}