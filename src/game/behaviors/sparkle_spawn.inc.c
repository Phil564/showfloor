void bhv_sparkle_spawn_loop(void) {
    o->oAnimState++;
    o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);

    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;

    o->oVelX = gMarioObject->oVelX;
    o->oVelY = gMarioObject->oVelY;
    o->oVelZ = gMarioObject->oVelZ;

    if (o->oPosY < o->oFloorHeight) {
        o->oPosY = o->oFloorHeight + 10.0f;
    }

    if (o->oTimer == 0) {
        obj_copy_pos(o, gMarioObject);
        obj_translate_xyz_random(o, 80.0f);
        o->oPosY += 20.0f;
    }

    if (o->oTimer > 12 || gMarioStates->action == ACT_IDLE || gMarioStates->action == ACT_WATER_PLUNGE)
        o->activeFlags = 0;
}
