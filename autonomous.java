package org.firstinspires.ftc.teamcode;

import com.qualcomm.robotcore.eventloop.opmode.Autonomous;
import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;

public class autonomous extends LinearOpMode {

    public void runOpMode() throws InterruptedException {
        hardware robot = new hardware();
        robot.init(hardwareMap);

        waitForStart();

        robot.moveForward(24);

        boolean isBlue = robot.isBlue();

        robot.moveBackward(24);

    }
}
