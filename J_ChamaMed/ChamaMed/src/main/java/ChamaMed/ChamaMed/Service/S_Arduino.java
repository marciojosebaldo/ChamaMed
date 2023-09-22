package ChamaMed.ChamaMed.Service;

import ch.qos.logback.core.net.SyslogOutputStream;
import com.fazecast.jSerialComm.SerialPort;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

public class S_Arduino {

    private static final String nomePortaArduino = "";
    private static final int baudRate = 9600;
    private static final int tempoEspera = 200;

    public static void Arduino() {
        SerialPort serialPort = SerialPort.getCommPort(nomePortaArduino);
        serialPort.setBaudRate(baudRate);

        if(!serialPort.openPort()) {
            System.err.println("Falha ao conectar com a porta serial");
            return;
        }

        InputStream inputStream = serialPort.getInputStream();
        boolean[] buffer = new boolean[42]; // São 42 portas no Arduino
        List<Boolean> portasArduino = new ArrayList<>();

        while(true) {

            try

        }


    }
}