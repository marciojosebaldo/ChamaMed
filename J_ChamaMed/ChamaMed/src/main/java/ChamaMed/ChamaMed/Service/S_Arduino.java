package ChamaMed.ChamaMed.Service;

import com.fazecast.jSerialComm.SerialPort;

public class S_Arduino {

    private static final String nomePortaArduino = "";
    private static final int baudRate = 9600;
    private static final int tempoEspera = 200;

    public static void Arduino() {
        SerialPort serialPort = SerialPort.getCommPort(nomePortaArduino);
        serialPort.setBaudRate(baudRate);


    }
}