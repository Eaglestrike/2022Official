#include <SwerveController.h>

SwerveController::SwerveController(){}


double 
SwerveController::calculateForward(double goal){
    return m_forwardcontroller.Calculate(m_forward, goal);
}


double 
SwerveController::calculateStrafe(double goal){
    return m_strafecontroller.Calculate(m_strafe, goal);
}


double 
SwerveController::calculateRotation(double goal){
    return m_rotationcontroller.Calculate(m_rotation, goal);
}


void
SwerveController::setPID(){
    double pGain_a = frc::SmartDashboard::GetNumber("P", 0.0);
    frc::SmartDashboard::PutNumber("P", pGain_a);
    double iGain_a = frc::SmartDashboard::GetNumber("I", 0.0);
    frc::SmartDashboard::PutNumber("I", iGain_a);
    double dGain_a = frc::SmartDashboard::GetNumber("D", 0.0);
    frc::SmartDashboard::PutNumber("D", dGain_a);
    m_forwardcontroller.SetPID(pGain_a, iGain_a, dGain_a);
    m_strafecontroller.SetPID(pGain_a, iGain_a, dGain_a);
}


void
SwerveController::setRotPID(){
    double pGain_a = frc::SmartDashboard::GetNumber("Prot", 0.0);
    frc::SmartDashboard::PutNumber("Prot", pGain_a);
    double iGain_a = frc::SmartDashboard::GetNumber("Irot", 0.0);
    frc::SmartDashboard::PutNumber("Irot", iGain_a);
    double dGain_a = frc::SmartDashboard::GetNumber("Drot", 0.0);
    frc::SmartDashboard::PutNumber("Drot", dGain_a);
    m_rotationcontroller.SetPID(pGain_a, iGain_a, dGain_a);
}


void
SwerveController::updatePosition(double forward, double strafe, double rotation){
    m_forward = forward;
    m_strafe = strafe;
    m_rotation = rotation;
}

