import requests
from django.http import JsonResponse


def handle_command(request, ip, command):
    url = f"http://{ip}/{command}"
    try:
        response = requests.get(url)
        return JsonResponse({'status': 'success', 'response': response.text})
    except requests.exceptions.RequestException as e:
        return JsonResponse({'status': 'error', 'message': str(e)})

