float GetAngle() const {
    FVector Forward = GetActorForwardVector(); //no problem on looking down, because character doesn't use controller pitch
    float ForwardAngle = FMath::Atan2(Forward.Y, Forward.X) * (180.f / PI); //Vector.Rotation() - unit vector's rotation - basically here getting Yaw Angle - Forward Yaw Angle

    FVector Velocity = GetVelocity();
    float VelocityAngle = FMath::Atan2(Velocity.Y, Velocity.X) * (180.f / PI); //Vector.Rotation() - unit vector's rotation - basically here getting Yaw Angle - Velocity Yaw Angle

    float DifferenceAngle = (VelocityAngle != 0.f) ? (VelocityAngle - ForwardAngle) : 0.f; //and the difference between of both Yaw Angles
    if (DifferenceAngle > 180.f) DifferenceAngle -= 360.f;
    if (DifferenceAngle < -180.f) DifferenceAngle += 360.f;

    UE_LOG(LogTemp, Warning, TEXT("ForwardAngle %f | VelocityAngle %f | DifferenceAngle %f"), ForwardAngle, VelocityAngle, DifferenceAngle);
    return DifferenceAngle;
}