for(SensorID = 1; SensorID <=NUMBEROFSENSOR;SensorID++){
lb:
 Sensor_X = DEVICE_POSITION(SensorID)->X - SinkNode_X; 
 // Finding relative x-axis position from SINK Centre
 Sensor_Y = SinkNode_Y - DEVICE_POSITION(SensorID)->Y; 
 // Finding relative y-axis position from SINK Centre
 
 Sensor_Sinknode_distance = fn_NetSim_Utilities_CalculateDistance
 (DEVICE_POSITION(NUMBEROFSENSOR + 1), DEVICE_POSITION(SensorID));
 for(i=0;i<NUMBEROFCONCENTRICCIRCLE+1;i++){ 
 if(Sensor_Sinknode_distance <= CONCENTRIC_DISTANCE[i]){
 Sensor_Angle = (180 * atan2(Sensor_Y,Sensor_X)) / PI;
 Arc = Sensor_Angle/angle;
 if(Arc >= 0){
 Arc = floor(Arc);
 }
 else{
     Arc = ceil(Arc);
 Arc = abs(Arc);
 Arc = RADIAL_LINES - 1 - Arc;
 }
 fprintf(cluster_log, "\n SensorID: %d => %f arc 
\n",SensorID,Arc);
 for(j=0;j< NUMBEROFSENSOR;j++){
 if(CLUSTER_DATA[i][(int)(Arc)][j] == 0){
 CLUSTER_DATA[i][(int)(Arc)][j] = SensorID;
 SensorID++;
 goto lb;
 }
 }
 }
 } 
 }
