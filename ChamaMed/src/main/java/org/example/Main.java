package org.example;

import com.fazecast.jSerialComm.*;

public class Main {
    public static void main(String[] args) {
        SerialPort sp = SerialPort.getCommPort("dev/ttyUSB0");
        sp.openPort();
        sp.setBaudRate(9600);

        String memoriaBuffer = "";

        boolean porta2 = false;
        boolean porta3 = false;
        boolean porta4 = false;
        boolean porta5 = false;
        boolean porta6 = false;

        try {
            while(true) {
                if (sp.bytesAvailable() > 0) {
                    byte[] leituraBuffer = new byte[sp.bytesAvailable()];
                    int qtdeLido = sp.readBytes(leituraBuffer, leituraBuffer.length);
                    String dadoRecebido = new String(leituraBuffer);

                    memoriaBuffer += dadoRecebido;

                    if (memoriaBuffer.contains("\n")) {
                        String[] linhas = memoriaBuffer.split("\n");
                            for (String linha : linhas) {
                                linha = linha.trim();
                                if (linha.equals("porta2Lig")) {
                                    porta2 = true;
                                } else if (linha.equals("porta2Des")) {
                                    porta2 = false;
                                } else if (linha.equals("porta3Lig")) {
                                    porta3 = true;
                                } else if (linha.equals("porta3Des")) {
                                    porta3 = false;
                                } else if (linha.equals("porta4Lig")) {
                                    porta4 = true;
                                } else if (linha.equals("porta4Des")) {
                                    porta4 = false;
                                } else if (linha.equals("porta5Lig")) {
                                    porta5 = true;
                                } else if (linha.equals("porta5Des")) {
                                    porta5 = false;
                                } else if (linha.equals("porta6Lig")) {
                                    porta6 = true;
                                } else if (linha.equals("porta6Des")) {
                                    porta6 = false;
                                }
                            }

                            memoriaBuffer = "";

                        System.out.println("Porta 2: " + porta2);
                        System.out.println("Porta 3: " + porta3);
                        System.out.println("Porta 4: " + porta4);
                        System.out.println("Porta 5: " + porta5);
                        System.out.println("Porta 6: " + porta6);
                        System.out.println();
                        System.out.println();
                    }
                }

                Thread.sleep(500);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        sp.closePort();
    }
}