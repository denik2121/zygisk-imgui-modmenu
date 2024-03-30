//
// Created by GoodGAmer on 22.01.2022.
//

#ifndef LOGGER_AMAPLOG_H
#define LOGGER_AMAPLOG_H
using namespace std;
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "HTTPRequest.hpp"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>


string gg;
extern "C" {
jobject getGlobalContext(JNIEnv *env) {
    jclass activityThread = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jmethodID currentActivityThread = env->GetStaticMethodID(activityThread,
                                                             OBFUSCATE("currentActivityThread"),
                                                             OBFUSCATE("()Landroid/app/ActivityThread;"));
    jobject at = env->CallStaticObjectMethod(activityThread, currentActivityThread);

    jmethodID getApplication = env->GetMethodID(activityThread, OBFUSCATE("getApplication"),
                                                OBFUSCATE("()Landroid/app/Application;"));
    jobject context = env->CallObjectMethod(at, getApplication);
    return context;
}
void Cock(JNIEnv *env, jobject thiz, const char *text, int length) {
    jstring jstr = env->NewStringUTF(text);
    jclass toast = env->FindClass(OBFUSCATE("android/widget/Toast"));
    jmethodID methodMakeText = env->GetStaticMethodID(toast, OBFUSCATE("makeText"),
                                                      OBFUSCATE("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
    jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText, thiz, jstr, length);
    jmethodID methodShow = env->GetMethodID(toast, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(toastobj, methodShow);
}
string getPublicStaticString(JNIEnv *env, const char *className, const char *fieldName) {
    jclass clazz = env->FindClass(className);
    if (clazz != nullptr) {
        jfieldID fid = env->GetStaticFieldID(clazz, fieldName, OBFUSCATE("Ljava/lang/String;"));
        if (fid != nullptr) {
            jstring GladioReceiver = (jstring) env->GetStaticObjectField(clazz, fid);
            jboolean blnIsCopy;
            string mystr = env->GetStringUTFChars(GladioReceiver, &blnIsCopy);
            return mystr;
        }
    }
    return OBFUSCATE("ERROR");
}
string get(string head, string url) {
    http::Request request{url};

    const auto response = request.send(OBFUSCATE("GET"), "", {head});
    return string{response.body.begin(), response.body.end()};
}
string Scam(JNIEnv *env) {
    const char *settings_name = OBFUSCATE("android/provider/Settings$Secure");
    const char *context_name = OBFUSCATE("android/content/Context");
    jclass class_settings_secure = env->FindClass(settings_name);
    jclass class_context = env->FindClass(context_name);
    jmethodID m_get_content_resolver = env->GetMethodID(class_context, OBFUSCATE("getContentResolver"), OBFUSCATE("()Landroid/content/ContentResolver;"));
    jfieldID f_android_id = env->GetStaticFieldID(class_settings_secure, OBFUSCATE("ANDROID_ID"), OBFUSCATE("Ljava/lang/String;"));
    jobject s_android_id = env->GetStaticObjectField(class_settings_secure, f_android_id);
    jobject o_content_resolver = env->CallObjectMethod(getGlobalContext(env), m_get_content_resolver);
    jmethodID m_get_string = env->GetStaticMethodID(class_settings_secure, OBFUSCATE("getString"), OBFUSCATE("(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;"));
    jstring android_id = (jstring) env->CallStaticObjectMethod(class_settings_secure, m_get_string, o_content_resolver, s_android_id);
    jboolean isCopy;
    string id = env->GetStringUTFChars(android_id, &isCopy);
    return id;
}
const char *getSignatures(JNIEnv *env, jobject context) {
    jclass native_context = env->GetObjectClass(context);
    jclass versionClass = env->FindClass(OBFUSCATE("android/os/Build$VERSION"));
    jfieldID sdkIntFieldID = env->GetStaticFieldID(versionClass, OBFUSCATE("SDK_INT"), OBFUSCATE("I"));
    int sdkInt = env->GetStaticIntField(versionClass, sdkIntFieldID);
    jclass contextClass = env->FindClass(OBFUSCATE("android/content/Context"));
    jmethodID pmMethod = env->GetMethodID(contextClass, OBFUSCATE("getPackageManager"), OBFUSCATE("()Landroid/content/pm/PackageManager;"));
    jobject pm = env->CallObjectMethod(context, pmMethod);
    jclass pmClass = env->GetObjectClass(pm);
    jmethodID piMethod = env->GetMethodID(pmClass, OBFUSCATE("getPackageInfo"), OBFUSCATE("(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;"));
    jmethodID pnMethod = env->GetMethodID( contextClass, OBFUSCATE("getPackageName"), OBFUSCATE("()Ljava/lang/String;"));
    jstring packageName = (jstring) (env->CallObjectMethod( context, pnMethod));
    int flags;
    if (sdkInt >= 28) {
        flags = 0x08000000; // PackageManager.GET_SIGNING_CERTIFICATES
    } else {
        flags = 0x00000040; // PackageManager.GET_SIGNATURES
    }
    jobject packageInfo = env->CallObjectMethod(pm, piMethod, packageName, flags);
    jclass piClass = env->GetObjectClass(packageInfo);
    jobjectArray signatures;
    if (sdkInt >= 28) {
        jfieldID signingInfoField = env->GetFieldID( piClass, OBFUSCATE("signingInfo"), OBFUSCATE("Landroid/content/pm/SigningInfo;"));
        jobject signingInfoObject = env->GetObjectField( packageInfo, signingInfoField);
        jclass signingInfoClass = env->GetObjectClass(signingInfoObject);
        jmethodID signaturesMethod = env->GetMethodID(signingInfoClass, OBFUSCATE("getApkContentsSigners"), OBFUSCATE("()[Landroid/content/pm/Signature;"));
        jobject signaturesObject = env->CallObjectMethod(signingInfoObject, signaturesMethod);
        signatures = (jobjectArray) (signaturesObject);
    } else {
        jfieldID signaturesField = env->GetFieldID( piClass, OBFUSCATE("signatures"), OBFUSCATE("[Landroid/content/pm/Signature;"));
        jobject signaturesObject = env->GetObjectField( packageInfo, signaturesField);
        if (env->IsSameObject( signaturesObject, NULL)) {
        }
        signatures = (jobjectArray) (signaturesObject);
    }
    jobject firstSignature = env->GetObjectArrayElement(signatures, 0);
    jclass signatureClass = env->GetObjectClass( firstSignature);
    jmethodID signatureByteMethod = env->GetMethodID( signatureClass, OBFUSCATE("toByteArray"), OBFUSCATE("()[B"));
    jobject signatureByteArray = (jobject) env->CallObjectMethod(firstSignature, signatureByteMethod);
    jclass mdClass = env->FindClass(OBFUSCATE("java/security/MessageDigest"));
    jmethodID mdMethod = env->GetStaticMethodID( mdClass, OBFUSCATE("getInstance"), OBFUSCATE("(Ljava/lang/String;)Ljava/security/MessageDigest;"));
    jobject md5Object = env->CallStaticObjectMethod(mdClass, mdMethod, env->NewStringUTF( OBFUSCATE("MD5")));
    jmethodID mdUpdateMethod = env->GetMethodID( mdClass, OBFUSCATE("update"), OBFUSCATE("([B)V"));// The return value of this function is void, write V
    env->CallVoidMethod(md5Object, mdUpdateMethod, signatureByteArray);
    jmethodID mdDigestMethod = env->GetMethodID( mdClass, OBFUSCATE("digest"), OBFUSCATE("()[B"));
    jbyteArray fingerPrintByteArray = (jbyteArray) env->CallObjectMethod(md5Object, mdDigestMethod);
    jsize byteArrayLength = env->GetArrayLength(fingerPrintByteArray);
    jbyte *fingerPrintByteArrayElements = env->GetByteArrayElements(fingerPrintByteArray, JNI_FALSE);
    char *charArray = (char *) fingerPrintByteArrayElements;
    char *md5 = (char *) calloc(2 * byteArrayLength + 1, sizeof(char));
    int k;
    for (k = 0; k < byteArrayLength; k++) {
        sprintf(&md5[2 * k], OBFUSCATE("%02X"), charArray[k]); 
    }
    return md5;
}
string GetDeviceId(JNIEnv *env) {
    string user = getPublicStaticString(env, OBFUSCATE("android/os/Build"), OBFUSCATE("USER"));
    string host = getPublicStaticString(env, OBFUSCATE("android/os/Build"), OBFUSCATE("HOST"));
    string version = getPublicStaticString(env, OBFUSCATE("android/os/Build$VERSION"), OBFUSCATE("RELEASE"));
    string id = Scam(env);
    
    string shsj = OBFUSCATE("-");
    string zgz = OBFUSCATE("---");
    string Gs = id;
    return Gs;
}
const char *getBaseApkAbsolutePath(JNIEnv *env, jobject stop) {
    const char* strGetApplicationInfo = OBFUSCATE("getApplicationInfo");
    const char* strContextClass = OBFUSCATE("android/content/Context");
    jclass _jcContext = env->FindClass(strContextClass);
    jmethodID _mGetApplicationInfo = env->GetMethodID(_jcContext, strGetApplicationInfo, OBFUSCATE("()Landroid/content/pm/ApplicationInfo;"));
    jobject result = env->CallObjectMethod(stop, _mGetApplicationInfo);
    const char* strSourceDir = OBFUSCATE("sourceDir");
    const char* strClass = OBFUSCATE("android/content/pm/ApplicationInfo");
    jclass _jcApplicationInfo = env->FindClass(strClass);
    jfieldID _fSourceDir = env->GetFieldID(_jcApplicationInfo, strSourceDir, OBFUSCATE("Ljava/lang/String;"));
    jstring reesult = (jstring)env->GetObjectField(result, _fSourceDir);
    const char* nativeString = env->GetStringUTFChars(reesult, 0);
    env->ReleaseStringUTFChars(reesult, nativeString);
    return nativeString;
}
JNIEXPORT jstring
JNICALL
Java_Weave_menu_B_target(
        JNIEnv *env,
        jobject contex) { 
    return env->NewStringUTF(GetDeviceId(env).c_str());
}
/*All for JNI*/
JNIEXPORT jstring
JNICALL
Java_Weave_menu_B_unk(
        JNIEnv *env,
        jobject activityObject) {
    jstring str = env->NewStringUTF(OBFUSCATE("<b><font color='green'>Неизвестное устройство : "));
    return str;
}

JNIEXPORT jstring
JNICALL
Java_Weave_menu_B_msgss(
        JNIEnv *env,
        jobject activityObject) {
    jstring str = env->NewStringUTF(OBFUSCATE("<b><font color='RED'>!!!!!!APK ПРИВАТ ЧТОБЫ ИГРАТЬ НУЖНО КУПИТЬ СОФТ!!!!! \n Канал разработчика https://t.me/pashaof \n САЙТ ДЛЯ ПОКУПКИ СОФТА https://xwidstore.ml/"));
    return str;
}

JNIEXPORT jstring
JNICALL
Java_Weave_menu_B_tos(
        JNIEnv *env,
        jobject activityObject) {
    jstring str = env->NewStringUTF(OBFUSCATE("<b><font color='BLUE'>!!!!DEVICE ID СКОПИРОВАН В БУФЕР ОБМЕНА!!!!"));
    return str;
}
}

#endif
