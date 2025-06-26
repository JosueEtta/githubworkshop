function validateForm(){
    let name = document.getElementById("name").value;   
    let email = document.getElementById("email").value;
    let password = document.getElementById("password").value;
    let confirm_password = document.getElementById("confirmPassword").value;

    let errorMessage = "";

    if(name === "" || email === "" || password === "" || confirm_password === ""){
        errorMessage = "All fields are required.";  
    }
    else if(password.length < 8){
        errorMessage = "Password must be at least 8 characters long.";
    }
    else if(password !== confirm_password){
        errorMessage = "Passwords do not match.";
    }
    if(errorMessage){
        document.getElementById("error-message").innerText = errorMessage;
        return false;
    }
    alert("Form submitted successfully!");
    return true;
}