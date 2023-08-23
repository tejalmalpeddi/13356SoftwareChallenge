# 13356SoftwareChallenge

# hardware.java file
package org.firstinspires.ftc.teamcode;

import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.ColorSensor;
import com.qualcomm.robotcore.hardware.HardwareMap;

public class hardware {
    DcMotor frontLeft, frontRight, rearLeft, rearRight;
    ColorSensor colorDistanceSensor;
    public hardware() {
    }
    public void init(HardwareMap hardwareMap) {
        frontLeft = hardwareMap.dcMotor.get("frontLeft");
        frontRight = hardwareMap.dcMotor.get("frontRight");
        rearLeft = hardwareMap.dcMotor.get("rearLeft");
        rearRight = hardwareMap.dcMotor.get("rearRight");
        colorDistanceSensor = hardwareMap.colorSensor.get("colorDistanceSensor");
        
        frontLeft.setDirection(DcMotor.Direction.FORWARD);
        frontRight.setDirection(DcMotor.Direction.REVERSE);
        rearLeft.setDirection(DcMotor.Direction.FORWARD);
        rearRight.setDirection(DcMotor.Direction.REVERSE);
    }

    public void moveForward(double inches) {
        double circumference = Math.PI * 4; // 4 inches diameter
        int targetCounts = (int) (inches * 288 / circumference);
        frontLeft.setTargetPosition(frontLeft.getCurrentPosition() + targetCounts);
        frontRight.setTargetPosition(frontRight.getCurrentPosition() + targetCounts);
        rearLeft.setTargetPosition(rearLeft.getCurrentPosition() + targetCounts);
        rearRight.setTargetPosition(rearRight.getCurrentPosition() + targetCounts);
       
        frontLeft.setMode(DcMotor.RunMode.RUN_TO_POSITION);
        frontRight.setMode(DcMotor.RunMode.RUN_TO_POSITION);
        rearLeft.setMode(DcMotor.RunMode.RUN_TO_POSITION);
        rearRight.setMode(DcMotor.RunMode.RUN_TO_POSITION);
  
        frontLeft.setPower(0.5);
        frontRight.setPower(0.5);
        rearLeft.setPower(0.5);
        rearRight.setPower(0.5);
        
        while (frontLeft.isBusy() || frontRight.isBusy() || rearLeft.isBusy() || rearRight.isBusy()) {
            
        }
        frontLeft.setPower(0);
        frontRight.setPower(0);
        rearLeft.setPower(0);
        rearRight.setPower(0);
        frontLeft.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
        frontRight.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
        rearLeft.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
        rearRight.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
    }

    public void moveBackward(double inches) {
    }

    public boolean isBlue() {
        return colorDistanceSensor.blue() > colorDistanceSensor.red();
    }
}
